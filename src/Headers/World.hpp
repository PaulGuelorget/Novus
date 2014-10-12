#ifndef BOOK_WORLD_HPP
#define BOOK_WORLD_HPP

#include "map.hpp"
#include "character.hpp"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <array>


// Forward declaration
namespace sf
{
	class RenderWindow;
}

class World : private sf::NonCopyable
{
	public:
		explicit							World(sf::RenderWindow& window, string Filename);
		void								update(sf::Time dt);
		void								draw();
		void 								handle(sf::Keyboard::Key key, bool b);



	private:
		void								loadTextures();
		void								buildScene();


	private:
		/*enum Layer
		{
			Background,
			Air,
			LayerCount
		}; */


	private:
		sf::RenderWindow&					mWindow;
        Map                                 mMap;
        Character							mCharacter;
		//sf::View							mWorldView;
        //TextureHolder						mTextures;

		//SceneNode							mSceneGraph;
		//std::array<SceneNode*, LayerCount>	mSceneLayers;

		//sf::FloatRect						mWorldBounds;
		//sf::Vector2f						mSpawnPosition;
		//float								mScrollSpeed;
        //Aircraft*							mPlayerAircraft;
};

#endif // BOOK_WORLD_HPP
